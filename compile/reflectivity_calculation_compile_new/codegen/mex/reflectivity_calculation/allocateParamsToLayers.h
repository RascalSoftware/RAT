/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * allocateParamsToLayers.h
 *
 * Code generation for function 'allocateParamsToLayers'
 *
 */

#pragma once

/* Include files */
#include "reflectivity_calculation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
  const emxArray_cell_wrap_14 *layersDetails, emxArray_cell_wrap_17 *outLayers);

/* End of code generation (allocateParamsToLayers.h) */
