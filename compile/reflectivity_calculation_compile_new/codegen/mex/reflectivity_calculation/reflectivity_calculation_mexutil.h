//
//  Non-Degree Granting Education License -- for use at non-degree
//  granting, nonprofit, educational organizations only. Not for
//  government, commercial, or other organizational use.
//
//  reflectivity_calculation_mexutil.h
//
//  Code generation for function 'reflectivity_calculation_mexutil'
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
#include "omp.h"
#include "reflectivity_calculation_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CODEGEN_EXPORT_SYM void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *u, const emlrtMsgIdentifier *parentId, real_T y[2]);
CODEGEN_EXPORT_SYM real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *u, const emlrtMsgIdentifier *parentId);
CODEGEN_EXPORT_SYM void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *
  src, const emlrtMsgIdentifier *msgId, real_T ret[2]);
CODEGEN_EXPORT_SYM emlrtCTX emlrtGetRootTLSGlobal();
CODEGEN_EXPORT_SYM void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const
  emlrtConstCTX aTLS, void *aData);
CODEGEN_EXPORT_SYM real_T fb_emlrt_marshallIn(const emlrtStack *sp, const
  mxArray *src, const emlrtMsgIdentifier *msgId);
CODEGEN_EXPORT_SYM void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *
  src, const emlrtMsgIdentifier *msgId, coder::array<real_T, 2U> &ret);

// End of code generation (reflectivity_calculation_mexutil.h)
