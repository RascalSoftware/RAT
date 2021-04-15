//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  _coder_callTestFun_api.cpp
//
//  Code generation for function '_coder_callTestFun_api'
//


// Include files
#include "_coder_callTestFun_api.h"
#include "callTestFun.h"
#include "callTestFun_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[9]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *params,
  const char_T *identifier))[4];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bulkIn,
  const char_T *identifier);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *funcName,
  const char_T *identifier, char_T y[9]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[9]);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[9])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *params,
  const char_T *identifier))[4]
{
  real_T (*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(params), &thisId);
  emlrtDestroyArray(&params);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bulkIn,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(bulkIn), &thisId);
  emlrtDestroyArray(&bulkIn);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *funcName,
  const char_T *identifier, char_T y[9])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(funcName), &thisId, y);
  emlrtDestroyArray(&funcName);
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[9])
{
  static const int32_T dims[2] = { 1, 9 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 9);
  emlrtDestroyArray(&src);
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  real_T (*ret)[4];
  static const int32_T dims[2] = { 1, 4 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void callTestFun_api(const mxArray * const prhs[5], int32_T nlhs, const mxArray *
                     plhs[2])
{
  char_T funcName[9];
  real_T (*params)[4];
  real_T bulkIn;
  real_T bulkOut;
  real_T contrast;
  const mxArray *output;
  const mxArray *sRough;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Marshall function inputs
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "funcName", funcName);
  params = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "params");
  bulkIn = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "bulkIn");
  bulkOut = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "bulkOut");
  contrast = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "contrast");

  // Invoke the target function
  callTestFun(&st, funcName, *params, bulkIn, bulkOut, contrast, &output,
              &sRough);

  // Marshall function outputs
  plhs[0] = output;
  if (nlhs > 1) {
    plhs[1] = sRough;
  }
}

// End of code generation (_coder_callTestFun_api.cpp)
