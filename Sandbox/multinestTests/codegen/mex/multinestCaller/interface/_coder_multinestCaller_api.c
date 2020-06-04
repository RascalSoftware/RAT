/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_multinestCaller_api.c
 *
 * Code generation for function '_coder_multinestCaller_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "multinestCaller.h"
#include "_coder_multinestCaller_api.h"
#include "multinestCaller_data.h"

/* Function Declarations */
static const mxArray *emlrt_marshallOut(void);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(void)
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 0, 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)NULL);
  emlrtSetDimensions((mxArray *)m1, iv2, 2);
  emlrtAssign(&y, m1);
  return y;
}

void multinestCaller_api(const mxArray *plhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  mxMalloc(0U);

  /* Invoke the target function */
  multinestCaller(&st);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut();
}

/* End of code generation (_coder_multinestCaller_api.c) */
