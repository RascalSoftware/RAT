//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_customBilayer_api.h
//
// Code generation for function 'customBilayer'
//

#ifndef _CODER_CUSTOMBILAYER_API_H
#define _CODER_CUSTOMBILAYER_API_H

// Include files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void customBilayer(coder::array<real_T, 1U> *params, real_T bulk_in,
                   real_T bulk_out[3], real_T contrast, real_T output[3][6],
                   real_T *sub_rough);

void customBilayer_api(const mxArray *const prhs[4], int32_T nlhs,
                       const mxArray *plhs[2]);

void customBilayer_atexit();

void customBilayer_initialize();

void customBilayer_terminate();

void customBilayer_xil_shutdown();

void customBilayer_xil_terminate();

#endif
// End of code generation (_coder_customBilayer_api.h)
