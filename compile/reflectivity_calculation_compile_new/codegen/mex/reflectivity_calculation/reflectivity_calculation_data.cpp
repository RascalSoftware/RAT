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
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
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

emlrtRSInfo m_emlrtRSI = { 63,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo n_emlrtRSI = { 74,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo o_emlrtRSI = { 81,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo p_emlrtRSI = { 87,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo q_emlrtRSI = { 91,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo r_emlrtRSI = { 94,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo s_emlrtRSI = { 97,         // lineNo
  "standardTF_layers_core",            // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pathName 
};

emlrtRSInfo ab_emlrtRSI = { 217,       // lineNo
  "charcmp",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

emlrtRSInfo bb_emlrtRSI = { 218,       // lineNo
  "charcmp",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

emlrtRSInfo cb_emlrtRSI = { 16,        // lineNo
  "lower",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/strfun/lower.m"// pathName
};

emlrtRSInfo db_emlrtRSI = { 10,        // lineNo
  "eml_string_transform",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"// pathName 
};

emlrtRSInfo fb_emlrtRSI = { 22,        // lineNo
  "cat",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo gb_emlrtRSI = { 102,       // lineNo
  "cat_impl",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo hb_emlrtRSI = { 12,        // lineNo
  "makeSLDProfiles",                   // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/makeSLDProfiles/makeSLDProfiles.m"// pathName 
};

emlrtRSInfo sb_emlrtRSI = { 20,        // lineNo
  "sum",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/sum.m"// pathName
};

emlrtRSInfo tb_emlrtRSI = { 99,        // lineNo
  "sumprod",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pathName 
};

emlrtRSInfo ub_emlrtRSI = { 125,       // lineNo
  "combineVectorElements",             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo vb_emlrtRSI = { 185,       // lineNo
  "colMajorFlatIter",                  // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"// pathName 
};

emlrtRSInfo wb_emlrtRSI = { 21,        // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

emlrtRSInfo bc_emlrtRSI = { 41,        // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"// pathName 
};

emlrtRSInfo cc_emlrtRSI = { 139,       // lineNo
  "scalar_float_power",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

emlrtRSInfo jc_emlrtRSI = { 62,        // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

emlrtRSInfo kc_emlrtRSI = { 51,        // lineNo
  "scalar_erf",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

emlrtRSInfo lc_emlrtRSI = { 236,       // lineNo
  "scalar_erf_and_erfc",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

emlrtRSInfo mc_emlrtRSI = { 238,       // lineNo
  "scalar_erf_and_erfc",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/specfun/private/eml_erfcore.m"// pathName 
};

emlrtRSInfo nc_emlrtRSI = { 17,        // lineNo
  "log2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/log2.m"// pathName
};

emlrtRSInfo oc_emlrtRSI = { 47,        // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

emlrtRSInfo pc_emlrtRSI = { 17,        // lineNo
  "log2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/log2.m"// pathName 
};

emlrtRSInfo qc_emlrtRSI = { 12,        // lineNo
  "pow2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/pow2.m"// pathName
};

emlrtRSInfo rc_emlrtRSI = { 49,        // lineNo
  "applyScalarFunction",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"// pathName 
};

emlrtRSInfo sc_emlrtRSI = { 12,        // lineNo
  "pow2",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+scalar/pow2.m"// pathName 
};

emlrtRSInfo vc_emlrtRSI = { 14,        // lineNo
  "max",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/max.m"// pathName
};

emlrtRSInfo wc_emlrtRSI = { 44,        // lineNo
  "minOrMax",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo xc_emlrtRSI = { 79,        // lineNo
  "maximum",                           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/minOrMax.m"// pathName 
};

emlrtRSInfo ad_emlrtRSI = { 1019,      // lineNo
  "maxRealVectorOmitNaN",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo bd_emlrtRSI = { 932,       // lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo cd_emlrtRSI = { 924,       // lineNo
  "minOrMaxRealVector",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo dd_emlrtRSI = { 992,       // lineNo
  "minOrMaxRealVectorKernel",          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pathName 
};

emlrtRSInfo od_emlrtRSI = { 41,        // lineNo
  "find",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo pd_emlrtRSI = { 153,       // lineNo
  "eml_find",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo qd_emlrtRSI = { 377,       // lineNo
  "find_first_indices",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo rd_emlrtRSI = { 397,       // lineNo
  "find_first_indices",                // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pathName
};

emlrtRSInfo oe_emlrtRSI = { 33,        // lineNo
  "applyScalarFunctionInPlace",        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"// pathName 
};

emlrtRSInfo ue_emlrtRSI = { 27,        // lineNo
  "cat",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pathName
};

emlrtRSInfo gf_emlrtRSI = { 17,        // lineNo
  "sortLE",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortLE.m"// pathName 
};

emlrtRSInfo hf_emlrtRSI = { 48,        // lineNo
  "sortrowsLE",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/sortrowsLE.m"// pathName 
};

emlrtRSInfo sf_emlrtRSI = { 288,       // lineNo
  "eml_float_colon",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pathName
};

emlrtRSInfo tf_emlrtRSI = { 306,       // lineNo
  "eml_float_colon",                   // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pathName
};

emlrtRSInfo vf_emlrtRSI = { 29,        // lineNo
  "abeles_single",                     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_single.m"// pathName 
};

emlrtRSInfo wf_emlrtRSI = { 45,        // lineNo
  "abeles_single",                     // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_single.m"// pathName 
};

emlrtRSInfo kg_emlrtRSI = { 32,        // lineNo
  "abeles_paraPoints",                 // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_paraPoints.m"// pathName 
};

emlrtRSInfo lg_emlrtRSI = { 48,        // lineNo
  "abeles_paraPoints",                 // fcnName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/reflectivityCalculations/Abeles/abeles_paraPoints.m"// pathName 
};

emlrtDCInfo rb_emlrtDCI = { 3,         // lineNo
  8,                                   // colNo
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",// pName 
  1                                    // checkKind
};

emlrtBCInfo qe_emlrtBCI = { -1,        // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  42,                                  // colNo
  "shifted_dat",                       // aName
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",// pName 
  0                                    // checkKind
};

emlrtBCInfo re_emlrtBCI = { -1,        // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  23,                                  // colNo
  "shifted_dat",                       // aName
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m",// pName 
  0                                    // checkKind
};

emlrtECInfo emlrtECI = { -1,           // nDims
  10,                                  // lineNo
  9,                                   // colNo
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"// pName 
};

emlrtRTEInfo nb_emlrtRTEI = { 283,     // lineNo
  27,                                  // colNo
  "check_non_axis_size",               // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/cat.m"// pName
};

emlrtRTEInfo rb_emlrtRTEI = { 46,      // lineNo
  23,                                  // colNo
  "sumprod",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pName 
};

emlrtRTEInfo vb_emlrtRTEI = { 387,     // lineNo
  1,                                   // colNo
  "find_first_indices",                // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

emlrtRTEInfo wb_emlrtRTEI = { 20,      // lineNo
  15,                                  // colNo
  "rdivide_helper",                    // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"// pName 
};

emlrtRTEInfo bc_emlrtRTEI = { 405,     // lineNo
  15,                                  // colNo
  "assert_pmaxsize",                   // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pName
};

emlrtRTEInfo cc_emlrtRTEI = { 14,      // lineNo
  9,                                   // colNo
  "asin",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elfun/asin.m"// pName
};

emlrtRTEInfo rg_emlrtRTEI = { 76,      // lineNo
  5,                                   // colNo
  "standardTF_layers_core",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pName 
};

emlrtRTEInfo sg_emlrtRTEI = { 74,      // lineNo
  5,                                   // colNo
  "standardTF_layers_core",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pName 
};

emlrtRTEInfo tg_emlrtRTEI = { 87,      // lineNo
  1,                                   // colNo
  "standardTF_layers_core",            // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/standard_TF/standardTF_layers_core.m"// pName 
};

emlrtRTEInfo ug_emlrtRTEI = { 6,       // lineNo
  9,                                   // colNo
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"// pName 
};

emlrtRTEInfo vg_emlrtRTEI = { 7,       // lineNo
  9,                                   // colNo
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"// pName 
};

emlrtRTEInfo wg_emlrtRTEI = { 10,      // lineNo
  28,                                  // colNo
  "applyBackgroundCorrection",         // fName
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/callReflectivity/applyBackgroundCorrection.m"// pName 
};

emlrtRTEInfo di_emlrtRTEI = { 153,     // lineNo
  13,                                  // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

emlrtRTEInfo ei_emlrtRTEI = { 41,      // lineNo
  5,                                   // colNo
  "find",                              // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/find.m"// pName
};

emlrtRTEInfo bk_emlrtRTEI = { 3,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo ck_emlrtRTEI = { 4,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo dk_emlrtRTEI = { 5,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo ek_emlrtRTEI = { 6,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo fk_emlrtRTEI = { 7,       // lineNo
  1,                                   // colNo
  "RAT_parse_cells",                   // fName
  "/home/arwel/Documents/RascalDev/RAT/API/RAT_parse_cells.m"// pName
};

emlrtRTEInfo gk_emlrtRTEI = { 8,       // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo hk_emlrtRTEI = { 9,       // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ik_emlrtRTEI = { 10,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo jk_emlrtRTEI = { 11,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo kk_emlrtRTEI = { 12,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo lk_emlrtRTEI = { 13,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo mk_emlrtRTEI = { 14,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo nk_emlrtRTEI = { 15,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo ok_emlrtRTEI = { 16,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo pk_emlrtRTEI = { 17,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo qk_emlrtRTEI = { 18,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo rk_emlrtRTEI = { 19,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo sk_emlrtRTEI = { 20,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo tk_emlrtRTEI = { 21,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo uk_emlrtRTEI = { 23,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo vk_emlrtRTEI = { 25,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

emlrtRTEInfo wk_emlrtRTEI = { 26,      // lineNo
  1,                                   // colNo
  "extractProblemParams",              // fName
  "/home/arwel/Documents/RascalDev/RAT/API/extractProblemParams.m"// pName
};

// End of code generation (reflectivity_calculation_data.cpp)
