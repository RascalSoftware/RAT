//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_interpolateOnToZ_api.cpp
//
//  Code generation for function '_coder_interpolateOnToZ_api'
//


// Include files
#include "_coder_interpolateOnToZ_api.h"
#include "interp1.h"
#include "interpolateOnToZ.h"
#include "interpolateOnToZ_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 1U> &y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier, coder::array<real_T, 2U> &y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 1U> &ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, coder::array<real_T, 1U> &y);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 1U> &y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *z, const
  char_T *identifier, coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(z), &thisId, y);
  emlrtDestroyArray(&z);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, coder::array<real_T, 2U> &y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 1U> &ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  ret.prealloc(iv[0]);
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0]);
  ret.set(((real_T *)emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, coder::array<real_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
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

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret.prealloc((iv[0] * iv[1]));
  ret.set_size(((emlrtRTEInfo *)NULL), sp, iv[0], iv[1]);
  ret.set(((real_T *)emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

void interpolateOnToZ_api(const mxArray * const prhs[3], int32_T, const mxArray *
  plhs[1])
{
  coder::array<real_T, 1U> X;
  coder::array<real_T, 1U> Y;
  coder::array<real_T, 2U> z;
  coder::array<real_T, 2U> newY;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  X.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X);
  Y.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Y", Y);
  z.no_free();
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "z", z);

  // Invoke the target function
  interpolateOnToZ(&st, X, Y, z, newY);

  // Marshall function outputs
  newY.no_free();
  plhs[0] = emlrt_marshallOut(newY);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_interpolateOnToZ_api.cpp)
