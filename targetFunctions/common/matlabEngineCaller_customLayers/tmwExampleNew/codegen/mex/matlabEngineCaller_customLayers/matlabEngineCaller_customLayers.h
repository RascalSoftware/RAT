/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * matlabEngineCaller_customLayers.h
 *
 * Code generation for function 'matlabEngineCaller_customLayers'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "matlabEngineCaller_customLayers_types.h"

/* Function Declarations */
void matlabEngineCaller_customLayers(const emlrtStack *sp, const real_T params[9],
  real_T contrast, const char_T funcName[10], const char_T funcPath[54], real_T
  bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough);

/* End of code generation (matlabEngineCaller_customLayers.h) */
