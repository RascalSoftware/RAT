//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  interpolateOnToZ_data.cpp
//
//  Code generation for function 'interpolateOnToZ_data'
//


// Include files
#include "interpolateOnToZ_data.h"
#include "interpolateOnToZ.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131594U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "interpolateOnToZ",                  // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo m_emlrtRSI = { 21,         // lineNo
  "eml_int_forloop_overflow_check",    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"// pathName 
};

emlrtRSInfo u_emlrtRSI = { 37,         // lineNo
  "flip",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/elmat/flip.m"// pathName
};

emlrtRTEInfo emlrtRTEI = { 26,         // lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"// pName 
};

// End of code generation (interpolateOnToZ_data.cpp)
