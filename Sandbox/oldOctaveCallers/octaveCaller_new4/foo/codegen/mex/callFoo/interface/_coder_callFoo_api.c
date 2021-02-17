/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_callFoo_api.c
 *
 * Code generation for function '_coder_callFoo_api'
 *
 */

/* Include files */
#include "_coder_callFoo_api.h"
#include "callFoo.h"
#include "callFoo_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void callFoo_api(int32_T nlhs, const mxArray *plhs[1])
{
  real_T y;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Invoke the target function */
  y = callFoo(&st);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(y);
}

/* End of code generation (_coder_callFoo_api.c) */
