//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_newModelBilayer_api.h
//
// Code generation for function 'newModelBilayer'
//

#ifndef _CODER_NEWMODELBILAYER_API_H
#define _CODER_NEWMODELBILAYER_API_H

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
void newModelBilayer(coder::array<real_T, 1U> *params, real_T bulk_in,
                     real_T bulk_out[3], real_T contrast,
                     real_T output[2][200]);

void newModelBilayer_api(const mxArray *const prhs[4], const mxArray **plhs);

void newModelBilayer_atexit();

void newModelBilayer_initialize();

void newModelBilayer_terminate();

void newModelBilayer_xil_shutdown();

void newModelBilayer_xil_terminate();

#endif
// End of code generation (_coder_newModelBilayer_api.h)
