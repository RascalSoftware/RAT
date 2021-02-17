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

emlrtRSInfo e_emlrtRSI = { 4,          /* lineNo */
  "standardTF_stanLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_stanLay_reflectivityCalculation.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 22,         /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 102,        /* lineNo */
  "cat_impl",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 12,         /* lineNo */
  "makeSLDProfiles",                   /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m"/* pathName */
};

emlrtRSInfo ob_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo pb_emlrtRSI = { 45,        /* lineNo */
  "mpower",                            /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

emlrtRSInfo sb_emlrtRSI = { 41,        /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo tb_emlrtRSI = { 139,       /* lineNo */
  "scalar_float_power",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo ub_emlrtRSI = { 39,        /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

emlrtRSInfo vb_emlrtRSI = { 40,        /* lineNo */
  "asymconvstep",                      /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/asymconvstep.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 51,        /* lineNo */
  "scalar_erf",                        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 236,       /* lineNo */
  "scalar_erf_and_erfc",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 238,       /* lineNo */
  "scalar_erf_and_erfc",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"/* pathName */
};

emlrtRSInfo fc_emlrtRSI = { 17,        /* lineNo */
  "log2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/log2.m"/* pathName */
};

emlrtRSInfo gc_emlrtRSI = { 47,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 17,        /* lineNo */
  "log2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/log2.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 12,        /* lineNo */
  "pow2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/pow2.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 49,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 12,        /* lineNo */
  "pow2",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/pow2.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 14,        /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 44,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 79,        /* lineNo */
  "maximum",                           /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 924,       /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo uc_emlrtRSI = { 992,       /* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo gd_emlrtRSI = { 41,        /* lineNo */
  "find",                              /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo hd_emlrtRSI = { 153,       /* lineNo */
  "eml_find",                          /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo id_emlrtRSI = { 377,       /* lineNo */
  "find_first_indices",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo jd_emlrtRSI = { 397,       /* lineNo */
  "find_first_indices",                /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 33,        /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

emlrtRSInfo xe_emlrtRSI = { 17,        /* lineNo */
  "sortLE",                            /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortLE.m"/* pathName */
};

emlrtRSInfo ye_emlrtRSI = { 48,        /* lineNo */
  "sortrowsLE",                        /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortrowsLE.m"/* pathName */
};

emlrtRSInfo of_emlrtRSI = { 306,       /* lineNo */
  "eml_float_colon",                   /* fcnName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo qf_emlrtRSI = { 29,        /* lineNo */
  "abeles_single",                     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m"/* pathName */
};

emlrtRSInfo rf_emlrtRSI = { 45,        /* lineNo */
  "abeles_single",                     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m"/* pathName */
};

emlrtRSInfo lg_emlrtRSI = { 32,        /* lineNo */
  "abeles_paraPoints",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pathName */
};

emlrtRSInfo mg_emlrtRSI = { 48,        /* lineNo */
  "abeles_paraPoints",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_paraPoints.m"/* pathName */
};

emlrtRSInfo xg_emlrtRSI = { 6,         /* lineNo */
  "standardTF_custLay_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pathName */
};

emlrtRSInfo mh_emlrtRSI = { 3,         /* lineNo */
  "call_customLayers",                 /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m"/* pathName */
};

emlrtRSInfo hi_emlrtRSI = { 6,         /* lineNo */
  "standardTF_custXY_reflectivityCalculation",/* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY_reflectivityCalculation.m"/* pathName */
};

emlrtRSInfo si_emlrtRSI = { 3,         /* lineNo */
  "call_customXY",                     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/call_customXY.m"/* pathName */
};

emlrtRTEInfo db_emlrtRTEI = { 283,     /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo gb_emlrtRTEI = { 46,      /* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

emlrtRTEInfo kb_emlrtRTEI = { 387,     /* lineNo */
  1,                                   /* colNo */
  "find_first_indices",                /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo lb_emlrtRTEI = { 20,      /* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"/* pName */
};

emlrtRTEInfo pb_emlrtRTEI = { 14,      /* lineNo */
  9,                                   /* colNo */
  "asin",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/asin.m"/* pName */
};

emlrtBCInfo lg_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  13,                                  /* colNo */
  "backs",                             /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

emlrtDCInfo jb_emlrtDCI = { 41,        /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo ng_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  14,                                  /* colNo */
  "shifts",                            /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

emlrtDCInfo kb_emlrtDCI = { 44,        /* lineNo */
  14,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo pg_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  10,                                  /* colNo */
  "sf",                                /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

emlrtDCInfo lb_emlrtDCI = { 47,        /* lineNo */
  10,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo rg_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  11,                                  /* colNo */
  "nba",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

emlrtDCInfo mb_emlrtDCI = { 50,        /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo tg_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  11,                                  /* colNo */
  "nbs",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

emlrtDCInfo nb_emlrtDCI = { 53,        /* lineNo */
  11,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo vg_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  13,                                  /* colNo */
  "res",                               /* aName */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  0                                    /* checkKind */
};

emlrtDCInfo ob_emlrtDCI = { 56,        /* lineNo */
  13,                                  /* colNo */
  "backSort",                          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/backSorts/backSort.m",/* pName */
  1                                    /* checkKind */
};

emlrtBCInfo dl_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "call_customLayers",                 /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay/call_customLayers.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo bs_emlrtBCI = { -1,        /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  17,                                  /* colNo */
  "params",                            /* aName */
  "call_customXY",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/call_customXY.m",/* pName */
  0                                    /* checkKind */
};

emlrtRTEInfo pe_emlrtRTEI = { 59,      /* lineNo */
  31,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

emlrtRTEInfo qe_emlrtRTEI = { 59,      /* lineNo */
  42,                                  /* colNo */
  "reflectivity_calculation",          /* fName */
  "/home/arwel/Documents/RascalDev/RAT/API/reflectivity_calculation/reflectivity_calculation.m"/* pName */
};

emlrtRTEInfo sf_emlrtRTEI = { 110,     /* lineNo */
  13,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

emlrtRTEInfo vf_emlrtRTEI = { 115,     /* lineNo */
  13,                                  /* colNo */
  "standardTF_custLay_reflectivityCalculation",/* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custLay_reflectivityCalculation.m"/* pName */
};

emlrtRTEInfo dj_emlrtRTEI = { 153,     /* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo fj_emlrtRTEI = { 41,      /* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo nj_emlrtRTEI = { 33,      /* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

emlrtRTEInfo iq_emlrtRTEI = { 9,       /* lineNo */
  14,                                  /* colNo */
  "call_customXY",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_custXY/call_customXY.m"/* pName */
};

const char_T cv[9] = { 'c', 'o', 'n', 't', 'r', 'a', 's', 't', 's' };

covrtInstance emlrtCoverageInstance;

/* End of code generation (reflectivity_calculation_data.c) */
