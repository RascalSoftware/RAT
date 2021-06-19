//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sld_convolute.h
//
// Code generation for function 'sld_convolute'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void sld_convolute(const emlrtStack *sp,
                   const coder::array<real_T, 2U> &b_signal,
                   const coder::array<real_T, 2U> &filter,
                   coder::array<real_T, 2U> &res);

// End of code generation (sld_convolute.h)
