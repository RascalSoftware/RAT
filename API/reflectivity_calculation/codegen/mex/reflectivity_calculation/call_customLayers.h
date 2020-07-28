/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_customLayers.h
 *
 * Code generation for function 'call_customLayers'
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
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
  real_T contrast, const emxArray_char_T *file, const emxArray_char_T *callPath,
  real_T bulkIn, real_T bulkOut, emxArray_real_T *output, real_T *sRough);

/* End of code generation (call_customLayers.h) */
