/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation.h
 *
 * Code generation for function 'reflectivity_calculation'
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
void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
  const cell_6 *problemDef_cells, const struct1_T *problemDef_limits, const
  struct2_T *controls, struct4_T *problem, cell_8 *result);

/* End of code generation (reflectivity_calculation.h) */
