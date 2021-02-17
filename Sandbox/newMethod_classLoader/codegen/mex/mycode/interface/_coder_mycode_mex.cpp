//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_mycode_mex.cpp
//
//  Code generation for function '_coder_mycode_mex'
//


// Include files
#include "_coder_mycode_mex.h"
#include "_coder_mycode_api.h"
#include "mycode.h"
#include "mycode_data.h"
#include "mycode_initialize.h"
#include "mycode_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mycode_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs);

// Function Definitions
void mycode_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs)
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4, 6,
                        "mycode");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 6,
                        "mycode");
  }

  // Call the function.
  mycode_api(nlhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray *[])
{
  mexAtExit(&mycode_atexit);

  // Module initialization.
  mycode_initialize();

  // Dispatch the entry-point.
  mycode_mexFunction(nlhs, plhs, nrhs);

  // Module termination.
  mycode_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_mycode_mex.cpp)
