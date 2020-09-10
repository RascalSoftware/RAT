/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * allocateLayersForContrast.h
 *
 * Code generation for function 'allocateLayersForContrast'
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
void allocateLayersForContrast(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, const emxArray_cell_wrap_17 *outParameterisedLayers,
  emxArray_real_T *thisContrastLayers);

/* End of code generation (allocateLayersForContrast.h) */
