/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * applyBackgroundCorrection.h
 *
 * Code generation for function 'applyBackgroundCorrection'
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
void applyBackgroundCorrection(const emlrtStack *sp, emxArray_real_T *reflect,
  emxArray_real_T *Simul, emxArray_real_T *shifted_dat, real_T backg, real_T
  backsType);

/* End of code generation (applyBackgroundCorrection.h) */
