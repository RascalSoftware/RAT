/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * resampleLayers.h
 *
 * Code generation for function 'resampleLayers'
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
void resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    emxArray_real_T *newSLD);

/* End of code generation (resampleLayers.h) */
