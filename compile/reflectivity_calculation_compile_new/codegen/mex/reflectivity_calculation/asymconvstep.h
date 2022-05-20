/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * asymconvstep.h
 *
 * Code generation for function 'asymconvstep'
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
void asymconvstep(const emlrtStack *sp, const emxArray_real_T *x, real_T xw,
                  real_T xcen, real_T s1, real_T s2, real_T h, emxArray_real_T
                  *f);

/* End of code generation (asymconvstep.h) */
