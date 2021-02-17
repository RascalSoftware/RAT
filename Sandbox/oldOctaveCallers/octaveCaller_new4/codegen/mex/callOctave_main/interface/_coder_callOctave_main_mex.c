/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callOctave_main_mex.c
 *
 * Code generation for function '_coder_callOctave_main_mex'
 *
 */

/* Include files */
#include "_coder_callOctave_main_mex.h"
#include "_coder_callOctave_main_api.h"
#include "callOctave_main.h"
#include "callOctave_main_data.h"
#include "callOctave_main_initialize.h"
#include "callOctave_main_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void callOctave_main_mexFunction(int32_T nlhs, int32_T nrhs);

/* Function Definitions */
void callOctave_main_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        15, "callOctave_main");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "callOctave_main");
  }

  /* Call the function. */
  callOctave_main_api(nlhs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)plhs;
  (void)prhs;
  mexAtExit(&callOctave_main_atexit);

  /* Module initialization. */
  callOctave_main_initialize();

  /* Dispatch the entry-point. */
  callOctave_main_mexFunction(nlhs, nrhs);

  /* Module termination. */
  callOctave_main_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_callOctave_main_mex.c) */
