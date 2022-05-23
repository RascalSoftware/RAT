/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * eml_mtimes_helper.h
 *
 * Code generation for function 'eml_mtimes_helper'
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
void b_binary_expand_op(const emlrtStack *sp, emxArray_real_T *f, real_T a,
                        const emxArray_real_T *r1);

void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *newDomain,
                        const emxArray_real_T *dataPoints,
                        const emxArray_int32_T *r2, const emxArray_int32_T *r3);

/* End of code generation (eml_mtimes_helper.h) */
