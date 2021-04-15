//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  callTestFun.h
//
//  Code generation for function 'callTestFun'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "callTestFun_types.h"

// Function Declarations
CODEGEN_EXPORT_SYM void callTestFun(const emlrtStack *sp, const char_T funcName
  [9], const real_T params[4], real_T bulkIn, real_T bulkOut, real_T contrast,
  const mxArray **output, const mxArray **sRough);

// End of code generation (callTestFun.h)
