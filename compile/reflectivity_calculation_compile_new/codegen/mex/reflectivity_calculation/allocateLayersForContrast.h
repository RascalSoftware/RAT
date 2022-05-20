/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * allocateLayersForContrast.h
 *
 * Code generation for function 'allocateLayersForContrast'
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
void allocateLayersForContrast(const emlrtStack *sp, const emxArray_real_T
  *contrastLayers, const emxArray_cell_wrap_17 *outParameterisedLayers,
  emxArray_real_T *thisContrastLayers);

/* End of code generation (allocateLayersForContrast.h) */
