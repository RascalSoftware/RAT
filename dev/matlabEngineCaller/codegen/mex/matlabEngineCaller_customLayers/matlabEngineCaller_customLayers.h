//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// matlabEngineCaller_customLayers.h
//
// Code generation for function 'matlabEngineCaller_customLayers'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void matlabEngineCaller_customLayers(
    const emlrtStack *sp, const coder::array<real_T, 2U> &params,
    real_T contrast, const coder::array<char_T, 2U> &funcName,
    const coder::array<char_T, 2U> &funcPath, real_T bulkIn, real_T bulkOut,
    coder::array<real_T, 2U> &output, real_T *sRough);

// End of code generation (matlabEngineCaller_customLayers.h)
