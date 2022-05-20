/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * resolution_polly.h
 *
 * Code generation for function 'resolution_polly'
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
void resolution_polly(const emlrtStack *sp, const emxArray_real_T *xdata, const
                      emxArray_real_T *ydata, real_T res, real_T points,
                      emxArray_real_T *out);

/* End of code generation (resolution_polly.h) */
