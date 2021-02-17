/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_octaveCaller_api.c
 *
 * Code generation for function '_coder_octaveCaller_api'
 *
 */

/* Include files */
#include "_coder_octaveCaller_api.h"
#include "octaveCaller.h"
#include "octaveCaller_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void octaveCaller_api(int32_T nlhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Invoke the target function */
  octaveCaller(&st);
}

/* End of code generation (_coder_octaveCaller_api.c) */
