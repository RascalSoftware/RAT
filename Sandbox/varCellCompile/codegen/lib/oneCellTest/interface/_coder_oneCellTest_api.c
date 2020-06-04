/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_oneCellTest_api.c
 *
 * Code generation for function '_coder_oneCellTest_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_oneCellTest_api.h"
#include "_coder_oneCellTest_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "oneCellTest",                       /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *cell1Length,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_cell_wrap_0 *u);
static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);
static void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0
  **pEmxArray, int32_T numDimensions, boolean_T doPush);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *cell1Length,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(cell1Length), &thisId);
  emlrtDestroyArray(&cell1Length);
  return y;
}

static const mxArray *emlrt_marshallOut(const emxArray_cell_wrap_0 *u)
{
  const mxArray *y;
  int32_T i0;
  int32_T n;
  const cell_wrap_0 *r0;
  int32_T u_size[2];
  int32_T i1;
  int32_T i;
  real_T tmp_data[30];
  int32_T loop_ub;
  int32_T i2;
  const mxArray *b_y;
  real_T u_data[30];
  const mxArray *m0;
  real_T *pData;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, *(int32_T (*)[2])u->size));
  i0 = 0;
  n = u->size[1];
  while (i0 < n) {
    r0 = &u->data[i0];
    u_size[0] = r0->f1.size[0];
    u_size[1] = 3;
    i1 = r0->f1.size[0];
    i = r0->f1.size[1];
    loop_ub = i1 * i;
    for (i2 = 0; i2 < loop_ub; i2++) {
      tmp_data[i2] = r0->f1.data[i2];
    }

    loop_ub = i1 * i;
    for (i1 = 0; i1 < loop_ub; i1++) {
      u_data[i1] = tmp_data[i1];
    }

    b_y = NULL;
    m0 = emlrtCreateNumericArray(2, u_size, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m0);
    i1 = 0;
    for (i = 0; i < 3; i++) {
      for (loop_ub = 0; loop_ub < u_size[0]; loop_ub++) {
        pData[i1] = u_data[loop_ub + u_size[0] * i];
        i1++;
      }
    }

    emlrtAssign(&b_y, m0);
    emlrtSetCell(y, i0, b_y);
    i0++;
  }

  return y;
}

static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

static void emxInit_cell_wrap_0(const emlrtStack *sp, emxArray_cell_wrap_0
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_0 *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_cell_wrap_0 *)emlrtMallocMex(sizeof
    (emxArray_cell_wrap_0));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_cell_wrap_0);
  }

  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void oneCellTest_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  emxArray_cell_wrap_0 *outResult;
  real_T cell1Length;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_cell_wrap_0(&st, &outResult, 2, true);

  /* Marshall function inputs */
  cell1Length = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "cell1Length");

  /* Invoke the target function */
  oneCellTest(cell1Length, outResult);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(outResult);
  emxFree_cell_wrap_0(&outResult);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void oneCellTest_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  oneCellTest_xil_terminate();
}

void oneCellTest_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void oneCellTest_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_oneCellTest_api.c) */
