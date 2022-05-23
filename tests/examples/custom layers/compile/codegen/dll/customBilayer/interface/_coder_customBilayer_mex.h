//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_customBilayer_mex.h
//
// Code generation for function 'customBilayer'
//

#ifndef _CODER_CUSTOMBILAYER_MEX_H
#define _CODER_CUSTOMBILAYER_MEX_H

// Include files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_customBilayer_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                      int32_T nrhs, const mxArray *prhs[4]);

#endif
// End of code generation (_coder_customBilayer_mex.h)
