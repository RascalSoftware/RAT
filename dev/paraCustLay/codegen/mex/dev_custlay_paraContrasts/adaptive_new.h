/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive_new.h
 *
 * Code generation for function 'adaptive_new'
 *
 */

#pragma once

/* Include files */
#include "dev_custlay_paraContrasts_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void adaptive_new(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                  const real_T startDomain[2], real_T minAngle, real_T nPoints,
                  cell_18 *out);

/* End of code generation (adaptive_new.h) */
