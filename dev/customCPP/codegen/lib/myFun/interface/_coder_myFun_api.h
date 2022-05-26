//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_myFun_api.h
//
// Code generation for function 'myFun'
//

#ifndef _CODER_MYFUN_API_H
#define _CODER_MYFUN_API_H

// Include files
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void myFun(real_T params[4], real_T foo, real_T bar, real_T out1[2][2],
           real_T *out2);

void myFun_api(const mxArray *const prhs[3], int32_T nlhs,
               const mxArray *plhs[2]);

void myFun_atexit();

void myFun_initialize();

void myFun_terminate();

void myFun_xil_shutdown();

void myFun_xil_terminate();

#endif
// End of code generation (_coder_myFun_api.h)
