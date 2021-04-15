//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_callTestFun_mex.cpp
//
//  Code generation for function '_coder_callTestFun_mex'
//


// Include files
#include "_coder_callTestFun_mex.h"
#include "_coder_callTestFun_api.h"
#include "callTestFun.h"
#include "callTestFun_data.h"
#include "callTestFun_initialize.h"
#include "callTestFun_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void callTestFun_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[5]);

// Function Definitions
void callTestFun_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[5])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        11, "callTestFun");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "callTestFun");
  }

  // Call the function.
  callTestFun_api(prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&callTestFun_atexit);

  // Module initialization.
  callTestFun_initialize();

  // Dispatch the entry-point.
  callTestFun_mexFunction(nlhs, plhs, nrhs, prhs);

  // Module termination.
  callTestFun_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_callTestFun_mex.cpp)
