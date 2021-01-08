/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mycode_api.c
 *
 * Code generation for function '_coder_mycode_api'
 *
 */

/* Include files */
#include "_coder_mycode_api.h"
#include "mycode.h"
#include "mycode_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const int32_T u);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const int32_T u)
{
  const mxArray *y;
  const mxArray *m;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

void mycode_api(int32_T nlhs, const mxArray *plhs[1])
{
  int32_T ret;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Invoke the target function */
  ret = mycode(&st);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(ret);
}

/* End of code generation (_coder_mycode_api.c) */
