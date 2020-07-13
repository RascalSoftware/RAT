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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
void allocateParamsToLayers(const emlrtStack *sp, const emxArray_real_T *params,
  const emxArray_cell_wrap_2 *layersDetails, emxArray_cell_wrap_14 *outLayers);

/* End of code generation (allocateParamsToLayers.h) */
