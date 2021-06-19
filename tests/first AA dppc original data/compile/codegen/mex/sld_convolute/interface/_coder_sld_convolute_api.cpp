//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_sld_convolute_api.cpp
//
//  Code generation for function '_coder_sld_convolute_api'
//


// Include files
#include "_coder_sld_convolute_api.h"
#include "rt_nonfinite.h"
#include "sld_convolute.h"
#include "sld_convolute_data.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_signal,
  const char_T *identifier, coder::array<real_T, 2U> &y);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { -1, 2 };

  const boolean_T bv[2] = { true, false };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.prealloc((iv[0] * iv[1]));
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  ret.set(((real_T *)emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_signal,
  const char_T *identifier, coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_signal), &thisId, y);
  emlrtDestroyArray(&b_signal);
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

void sld_convolute_api(const mxArray * const prhs[2], int32_T, const mxArray
  *plhs[1])
{
  coder::array<real_T, 2U> b_signal;
  coder::array<real_T, 2U> filter;
  coder::array<real_T, 2U> res;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  b_signal.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "signal", b_signal);
  filter.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "filter", filter);

  // Invoke the target function
  sld_convolute(&st, b_signal, filter, res);

  // Marshall function outputs
  res.no_free();
  plhs[0] = emlrt_marshallOut(res);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_sld_convolute_api.cpp)
