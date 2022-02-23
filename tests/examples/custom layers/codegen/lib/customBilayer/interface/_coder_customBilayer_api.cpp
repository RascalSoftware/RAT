//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// _coder_customBilayer_api.cpp
//
// Code generation for function 'customBilayer'
//

// Include files
#include "_coder_customBilayer_api.h"
#include "_coder_customBilayer_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131610U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "customBilayer",                                      // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bulk_in,
                                 const char_T *identifier);

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[8];

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *params,
                                 const char_T *identifier))[8];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[8];

static const mxArray *emlrt_marshallOut(const real_T u[18]);

static const mxArray *emlrt_marshallOut(const real_T u);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bulk_in,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(bulk_in), &thisId);
  emlrtDestroyArray(&bulk_in);
  return y;
}

static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[8]
{
  static const int32_T dims[2]{1, 8};
  real_T(*ret)[8];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[8])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *params,
                                 const char_T *identifier))[8]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[8];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(params), &thisId);
  emlrtDestroyArray(&params);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[8]
{
  real_T(*y)[8];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[18])
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv1[2]{6, 3};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void customBilayer_api(const mxArray *const prhs[4], int32_T nlhs,
                       const mxArray *plhs[2])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*output)[18];
  real_T(*params)[8];
  real_T bulk_in;
  real_T bulk_out;
  real_T contrast;
  real_T sub_rough;
  st.tls = emlrtRootTLSGlobal;
  output = (real_T(*)[18])mxMalloc(sizeof(real_T[18]));
  // Marshall function inputs
  params = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "params");
  bulk_in = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "bulk_in");
  bulk_out = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "bulk_out");
  contrast = b_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "contrast");
  // Invoke the target function
  customBilayer(*params, bulk_in, bulk_out, contrast, *output, &sub_rough);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(*output);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(sub_rough);
  }
}

void customBilayer_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  customBilayer_xil_terminate();
  customBilayer_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void customBilayer_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void customBilayer_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (_coder_customBilayer_api.cpp)
