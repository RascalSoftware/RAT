/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * sumMatrixIncludeNaN.h
 *
 * Code generation for function 'sumMatrixIncludeNaN'
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
real_T b_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                    int32_T vlen, int32_T vstart);

real_T sumColumnB(const emlrtStack *sp, const emxArray_real_T *x, int32_T vlen);

real_T sumColumnB4(const emxArray_real_T *x, int32_T vstart);

/* End of code generation (sumMatrixIncludeNaN.h) */
