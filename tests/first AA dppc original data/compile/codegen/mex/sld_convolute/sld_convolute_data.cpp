//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  sld_convolute_data.cpp
//
//  Code generation for function 'sld_convolute_data'
//


// Include files
#include "sld_convolute_data.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131594U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "sld_convolute",                     // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo n_emlrtRSI = { 63,         // lineNo
  "Linspace",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/linspace.m"// pathName
};

emlrtRSInfo o_emlrtRSI = { 21,         // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

emlrtRSInfo v_emlrtRSI = { 37,         // lineNo
  "flip",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/flip.m"// pathName
};

emlrtRSInfo pb_emlrtRSI = { 61,        // lineNo
  "xaxpy",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"// pathName 
};

emlrtRSInfo qb_emlrtRSI = { 60,        // lineNo
  "xaxpy",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+blas/xaxpy.m"// pathName 
};

emlrtRTEInfo g_emlrtRTEI = { 128,      // lineNo
  19,                                  // colNo
  "interp1_work",                      // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/polyfun/interp1.m"// pName
};

emlrtRTEInfo h_emlrtRTEI = { 46,       // lineNo
  23,                                  // colNo
  "sumprod",                           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"// pName 
};

// End of code generation (sld_convolute_data.cpp)
