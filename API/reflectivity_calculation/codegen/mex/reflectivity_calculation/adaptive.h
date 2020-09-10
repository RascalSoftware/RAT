/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * adaptive.h
 *
 * Code generation for function 'adaptive'
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
void calculateCentralAngles(const emlrtStack *sp, const emxArray_real_T *XYdata,
  const real_T dataBoxSize[2], emxArray_real_T *cornerAngle);
void increaseSampling(const emlrtStack *sp, emxArray_real_T *dataPoints, const
                      emxArray_boolean_T *segmentsToSplit, const emxArray_real_T
                      *sldProfile);

/* End of code generation (adaptive.h) */
