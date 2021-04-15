/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_backSort_api.c
 *
 * Code generation for function '_coder_backSort_api'
 *
 */

/* Include files */
#include "tmwtypes.h"
#include "_coder_backSort_api.h"
#include "_coder_backSort_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131435U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "backSort",                          /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void b_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *backs, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *cBacks,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *backs, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(backs), &thisId, y);
  emlrtDestroyArray(&backs);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *cBacks,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(cBacks), &thisId);
  emlrtDestroyArray(&cBacks);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  boolean_T bv0[2] = { false, true };

  int32_T iv0[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv0);
  ret->size[0] = iv0[0];
  ret->size[1] = iv0[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void backSort_api(const mxArray *prhs[12], const mxArray *plhs[6])
{
  emxArray_real_T *backs;
  emxArray_real_T *shifts;
  emxArray_real_T *sf;
  emxArray_real_T *nba;
  emxArray_real_T *nbs;
  emxArray_real_T *res;
  real_T cBacks;
  real_T cShifts;
  real_T cScales;
  real_T cNbas;
  real_T cNbss;
  real_T cRes;
  real_T backg;
  real_T qshift;
  real_T resol;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &backs, 2, true);
  emxInit_real_T(&st, &shifts, 2, true);
  emxInit_real_T(&st, &sf, 2, true);
  emxInit_real_T(&st, &nba, 2, true);
  emxInit_real_T(&st, &nbs, 2, true);
  emxInit_real_T(&st, &res, 2, true);
  prhs[6] = emlrtProtectR2012b(prhs[6], 6, false, -1);
  prhs[7] = emlrtProtectR2012b(prhs[7], 7, false, -1);
  prhs[8] = emlrtProtectR2012b(prhs[8], 8, true, -1);
  prhs[9] = emlrtProtectR2012b(prhs[9], 9, true, -1);
  prhs[10] = emlrtProtectR2012b(prhs[10], 10, true, -1);
  prhs[11] = emlrtProtectR2012b(prhs[11], 11, false, -1);

  /* Marshall function inputs */
  cBacks = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "cBacks");
  cShifts = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "cShifts");
  cScales = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "cScales");
  cNbas = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "cNbas");
  cNbss = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "cNbss");
  cRes = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "cRes");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "backs", backs);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "shifts", shifts);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "sf", sf);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "nba", nba);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "nbs", nbs);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "res", res);

  /* Invoke the target function */
  backSort(cBacks, cShifts, cScales, cNbas, cNbss, cRes, backs, shifts, sf, nba,
           nbs, res, &backg, &qshift, &resol);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(backg);
  plhs[1] = emlrt_marshallOut(qshift);
  b_emlrt_marshallOut(sf, prhs[8]);
  plhs[2] = prhs[8];
  b_emlrt_marshallOut(nba, prhs[9]);
  plhs[3] = prhs[9];
  b_emlrt_marshallOut(nbs, prhs[10]);
  plhs[4] = prhs[10];
  plhs[5] = emlrt_marshallOut(resol);
  res->canFreeData = false;
  emxFree_real_T(&res);
  nbs->canFreeData = false;
  emxFree_real_T(&nbs);
  nba->canFreeData = false;
  emxFree_real_T(&nba);
  sf->canFreeData = false;
  emxFree_real_T(&sf);
  shifts->canFreeData = false;
  emxFree_real_T(&shifts);
  backs->canFreeData = false;
  emxFree_real_T(&backs);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void backSort_atexit(void)
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
  backSort_xil_terminate();
}

void backSort_initialize(void)
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

void backSort_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_backSort_api.c) */
