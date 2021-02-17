/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callOctave_main_api.c
 *
 * Code generation for function '_coder_callOctave_main_api'
 *
 */

/* Include files */
#include "_coder_callOctave_main_api.h"
#include "callOctave_main.h"
#include "callOctave_main_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void callOctave_main_api(int32_T nlhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Invoke the target function */
  callOctave_main(&st);
}

/* End of code generation (_coder_callOctave_main_api.c) */
