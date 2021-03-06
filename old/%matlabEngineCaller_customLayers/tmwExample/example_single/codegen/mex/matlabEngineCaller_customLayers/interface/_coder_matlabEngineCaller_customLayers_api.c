/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_matlabEngineCaller_customLayers_api.c
 *
 * Code generation for function '_coder_matlabEngineCaller_customLayers_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "matlabEngineCaller_customLayers.h"
#include "_coder_matlabEngineCaller_customLayers_api.h"
#include "matlabEngineCaller_customLayers_emxutil.h"
#include "matlabEngineCaller_customLayers_data.h"

/* Variable Definitions */
static emlrtRTEInfo d_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_matlabEngineCaller_customLayers_api",/* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8];
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *contrast,
  const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *funcName,
  const char_T *identifier, emxArray_char_T *y);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *params,
  const char_T *identifier))[8];
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8];
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8]
{
  real_T (*y)[8];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m1, u_size, 2);
  emlrtAssign(&y, m1);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *contrast,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(contrast), &thisId);
  emlrtDestroyArray(&contrast);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *funcName,
  const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(funcName), &thisId, y);
  emlrtDestroyArray(&funcName);
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *params,
  const char_T *identifier))[8]
{
  real_T (*y)[8];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(params), &thisId);
  emlrtDestroyArray(&params);
  return y;
}
  static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, &u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8]
{
  real_T (*ret)[8];
  static const int32_T dims[2] = { 1, 8 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[8])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv2[2];
  int32_T i2;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv0[0],
    iv2);
  i2 = ret->size[0] * ret->size[1];
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  emxEnsureCapacity_char_T(sp, ret, i2, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

void matlabEngineCaller_customLayers_api(const mxArray * const prhs[6], int32_T
  nlhs, const mxArray *plhs[2])
{
  real_T (*sRough_data)[1];
  emxArray_char_T *funcName;
  emxArray_char_T *funcPath;
  emxArray_real_T *output;
  real_T (*params)[8];
  real_T contrast;
  real_T bulkIn;
  real_T bulkOut;
  int32_T sRough_size[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  sRough_data = (real_T (*)[1])mxMalloc(sizeof(real_T [1]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_char_T(&st, &funcName, 2, &d_emlrtRTEI, true);
  emxInit_char_T(&st, &funcPath, 2, &d_emlrtRTEI, true);
  emxInit_real_T(&st, &output, 2, &d_emlrtRTEI, true);

  /* Marshall function inputs */
  params = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "params");
  contrast = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "contrast");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "funcName", funcName);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "funcPath", funcPath);
  bulkIn = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "bulkIn");
  bulkOut = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "bulkOut");

  /* Invoke the target function */
  matlabEngineCaller_customLayers(&st, *params, contrast, funcName, funcPath,
    bulkIn, bulkOut, output, *sRough_data, sRough_size);

  /* Marshall function outputs */
  output->canFreeData = false;
  plhs[0] = emlrt_marshallOut(output);
  emxFree_real_T(&output);
  emxFree_char_T(&funcPath);
  emxFree_char_T(&funcName);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*sRough_data, sRough_size);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_matlabEngineCaller_customLayers_api.c) */
