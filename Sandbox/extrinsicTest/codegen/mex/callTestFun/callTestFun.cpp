//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  callTestFun.cpp
//
//  Code generation for function 'callTestFun'
//


// Include files
#include "callTestFun.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtMCInfo emlrtMCI = { 24,    // lineNo
  5,                                   // colNo
  "callTestFun",                       // fName
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/extrinsicTest/callTestFun.m"// pName 
};

static emlrtRSInfo emlrtRSI = { 24,    // lineNo
  "callTestFun",                       // fcnName
  "/home/arwel/Documents/RascalDev/RAT/Sandbox/extrinsicTest/callTestFun.m"// pathName 
};

// Function Declarations
static void feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  const mxArray *d, const mxArray *e, const mxArray *f,
                  emlrtMCInfo *location, const mxArray **g, const mxArray **h);

// Function Definitions
static void feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  const mxArray *d, const mxArray *e, const mxArray *f,
                  emlrtMCInfo *location, const mxArray **g, const mxArray **h)
{
  const mxArray *pArrays[5];
  const mxArray *mv[2];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  emlrtAssign(g, emlrtCallMATLABR2012b(sp, 2, &mv[0], 5, &pArrays[0], "feval",
    true, location));
  emlrtAssign(h, mv[1]);
}

void callTestFun(const emlrtStack *sp, const char_T funcName[9], const real_T
                 params[4], real_T bulkIn, real_T bulkOut, real_T contrast,
                 const mxArray **output, const mxArray **sRough)
{
  const mxArray *b_output;
  const mxArray *b_sRough;
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 9 };

  const mxArray *b_y;
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 4 };

  real_T *pData;
  const mxArray *m1;
  const mxArray *d_y;
  const mxArray *m2;
  const mxArray *e_y;
  const mxArray *m3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  *sRough = NULL;
  *output = NULL;
  b_output = NULL;
  b_sRough = NULL;

  //  if isempty(fileHandle)
  //
  //      dotM = strfind(funcName,'.m');
  //      if ~isempty(dotM)
  //          funcName = funcName(1:dotM-1);
  //      end
  //
  //      fullFunc = [path funcName];
  //      fileHandle = str2func(fullFunc);
  //  end
  //
  // ff = [funcName '(params,bulkIn,bulkOut,contrast)'];
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(sp, 9, m, &funcName[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  c_y = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(c_y);
  pData[0] = params[0];
  pData[1] = params[1];
  pData[2] = params[2];
  pData[3] = params[3];
  emlrtAssign(&b_y, c_y);
  c_y = NULL;
  m1 = emlrtCreateDoubleScalar(bulkIn);
  emlrtAssign(&c_y, m1);
  d_y = NULL;
  m2 = emlrtCreateDoubleScalar(bulkOut);
  emlrtAssign(&d_y, m2);
  e_y = NULL;
  m3 = emlrtCreateDoubleScalar(contrast);
  emlrtAssign(&e_y, m3);
  st.site = &emlrtRSI;
  feval(&st, y, b_y, c_y, d_y, e_y, &emlrtMCI, &b_output, &b_sRough);
  emlrtAssign(output, emlrtAlias(b_output));
  emlrtAssign(sRough, emlrtAlias(b_sRough));
  emlrtDestroyArray(&b_output);
  emlrtDestroyArray(&b_sRough);
}

// End of code generation (callTestFun.cpp)
