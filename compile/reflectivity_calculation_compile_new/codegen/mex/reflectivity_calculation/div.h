/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * div.h
 *
 * Code generation for function 'div'
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
void i_binary_expand_op(const emlrtStack *sp, emxArray_real_T *terms,
                        const emxArray_real_T *thisData);

void rdivide(const emlrtStack *sp, emxArray_real_T *normalizedData,
             const emxArray_real_T *XYdata);

/* End of code generation (div.h) */
