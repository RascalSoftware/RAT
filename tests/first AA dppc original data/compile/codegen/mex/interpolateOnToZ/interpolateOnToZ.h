//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// interpolateOnToZ.h
//
// Code generation for function 'interpolateOnToZ'
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

void interpolateOnToZ(const emlrtStack *sp, const coder::array<real_T, 1U> &X,
                      const coder::array<real_T, 1U> &Y,
                      const coder::array<real_T, 2U> &z,
                      coder::array<real_T, 2U> &newY);

// End of code generation (interpolateOnToZ.h)
