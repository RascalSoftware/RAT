/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resolution_polly_paraPoints.h
 *
 * Code generation for function 'resolution_polly_paraPoints'
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
void resolution_polly_paraPoints(const emlrtStack *sp, const emxArray_real_T
  *xdata, const emxArray_real_T *ydata, real_T res, real_T points,
  emxArray_real_T *out);

/* End of code generation (resolution_polly_paraPoints.h) */
