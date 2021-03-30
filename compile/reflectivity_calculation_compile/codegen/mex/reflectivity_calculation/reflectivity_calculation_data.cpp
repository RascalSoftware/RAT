//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_data.cpp
//
//  Code generation for function 'reflectivity_calculation_data'
//


// Include files
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131594U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "reflectivity_calculation",          // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo y_emlrtRSI = { 217,        // lineNo
  "charcmp",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

emlrtRSInfo ab_emlrtRSI = { 218,       // lineNo
  "charcmp",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

emlrtRSInfo bb_emlrtRSI = { 16,        // lineNo
  "lower",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/strfun/lower.m"// pathName
};

emlrtRSInfo cb_emlrtRSI = { 10,        // lineNo
  "eml_string_transform",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"// pathName 
};

emlrtRSInfo eb_emlrtRSI = { 22,        // lineNo
  "cat",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo fb_emlrtRSI = { 102,       // lineNo
  "cat_impl",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo rb_emlrtRSI = { 20,        // lineNo
  "sum",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sum.m"// pathName
};

emlrtRSInfo sb_emlrtRSI = { 99,        // lineNo
  "sumprod",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pathName 
};

emlrtRSInfo tb_emlrtRSI = { 125,       // lineNo
  "combineVectorElements",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo ub_emlrtRSI = { 185,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo vb_emlrtRSI = { 21,        // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

emlrtRSInfo ac_emlrtRSI = { 41,        // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

emlrtRSInfo bc_emlrtRSI = { 139,       // lineNo
  "scalar_float_power",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

emlrtRSInfo ic_emlrtRSI = { 62,        // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

emlrtRSInfo jc_emlrtRSI = { 51,        // lineNo
  "scalar_erf",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

emlrtRSInfo kc_emlrtRSI = { 236,       // lineNo
  "scalar_erf_and_erfc",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

emlrtRSInfo lc_emlrtRSI = { 238,       // lineNo
  "scalar_erf_and_erfc",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

emlrtRSInfo mc_emlrtRSI = { 17,        // lineNo
  "log2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/log2.m"// pathName
};

emlrtRSInfo nc_emlrtRSI = { 47,        // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

emlrtRSInfo oc_emlrtRSI = { 17,        // lineNo
  "log2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/log2.m"// pathName 
};

emlrtRSInfo pc_emlrtRSI = { 12,        // lineNo
  "pow2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/pow2.m"// pathName
};

emlrtRSInfo qc_emlrtRSI = { 49,        // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

emlrtRSInfo rc_emlrtRSI = { 12,        // lineNo
  "pow2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/pow2.m"// pathName 
};

emlrtRSInfo uc_emlrtRSI = { 14,        // lineNo
  "max",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/max.m"// pathName
};

emlrtRSInfo vc_emlrtRSI = { 44,        // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo wc_emlrtRSI = { 79,        // lineNo
  "maximum",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo yc_emlrtRSI = { 1019,      // lineNo
  "maxRealVectorOmitNaN",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo ad_emlrtRSI = { 932,       // lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo bd_emlrtRSI = { 924,       // lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo cd_emlrtRSI = { 992,       // lineNo
  "minOrMaxRealVectorKernel",          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo nd_emlrtRSI = { 41,        // lineNo
  "find",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo od_emlrtRSI = { 153,       // lineNo
  "eml_find",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo pd_emlrtRSI = { 377,       // lineNo
  "find_first_indices",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo qd_emlrtRSI = { 397,       // lineNo
  "find_first_indices",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo ne_emlrtRSI = { 33,        // lineNo
  "applyScalarFunctionInPlace",        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"// pathName 
};

emlrtRSInfo te_emlrtRSI = { 27,        // lineNo
  "cat",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo ff_emlrtRSI = { 17,        // lineNo
  "sortLE",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortLE.m"// pathName 
};

emlrtRSInfo gf_emlrtRSI = { 48,        // lineNo
  "sortrowsLE",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortrowsLE.m"// pathName 
};

emlrtRSInfo rf_emlrtRSI = { 288,       // lineNo
  "eml_float_colon",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pathName
};

emlrtRSInfo sf_emlrtRSI = { 306,       // lineNo
  "eml_float_colon",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pathName
};

emlrtRSInfo uf_emlrtRSI = { 29,        // lineNo
  "abeles_single",                     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_single.m"// pathName 
};

emlrtRSInfo vf_emlrtRSI = { 45,        // lineNo
  "abeles_single",                     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_single.m"// pathName 
};

emlrtRSInfo jg_emlrtRSI = { 32,        // lineNo
  "abeles_paraPoints",                 // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_paraPoints.m"// pathName 
};

emlrtRSInfo kg_emlrtRSI = { 48,        // lineNo
  "abeles_paraPoints",                 // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_paraPoints.m"// pathName 
};

emlrtRTEInfo ib_emlrtRTEI = { 283,     // lineNo
  27,                                  // colNo
  "check_non_axis_size",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pName
};

emlrtRTEInfo lb_emlrtRTEI = { 46,      // lineNo
  23,                                  // colNo
  "sumprod",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pName 
};

emlrtRTEInfo pb_emlrtRTEI = { 387,     // lineNo
  1,                                   // colNo
  "find_first_indices",                // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

emlrtRTEInfo qb_emlrtRTEI = { 20,      // lineNo
  15,                                  // colNo
  "rdivide_helper",                    // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"// pName 
};

emlrtRTEInfo ub_emlrtRTEI = { 405,     // lineNo
  15,                                  // colNo
  "assert_pmaxsize",                   // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pName
};

emlrtRTEInfo vb_emlrtRTEI = { 14,      // lineNo
  9,                                   // colNo
  "asin",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/asin.m"// pName
};

emlrtRTEInfo eg_emlrtRTEI = { 153,     // lineNo
  13,                                  // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

emlrtRTEInfo fg_emlrtRTEI = { 41,      // lineNo
  5,                                   // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

emlrtRTEInfo ci_emlrtRTEI = { 3,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo di_emlrtRTEI = { 4,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo ei_emlrtRTEI = { 5,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo fi_emlrtRTEI = { 6,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo gi_emlrtRTEI = { 7,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo hi_emlrtRTEI = { 8,       // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ii_emlrtRTEI = { 9,       // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ji_emlrtRTEI = { 10,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ki_emlrtRTEI = { 11,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo li_emlrtRTEI = { 12,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo mi_emlrtRTEI = { 13,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ni_emlrtRTEI = { 14,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo oi_emlrtRTEI = { 15,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo pi_emlrtRTEI = { 16,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo qi_emlrtRTEI = { 17,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ri_emlrtRTEI = { 18,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo si_emlrtRTEI = { 19,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ti_emlrtRTEI = { 20,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ui_emlrtRTEI = { 21,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo vi_emlrtRTEI = { 23,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo wi_emlrtRTEI = { 25,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo xi_emlrtRTEI = { 26,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

// End of code generation (reflectivity_calculation_data.cpp)
