/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfileXY.h
 *
 * Code generation for function 'makeSLDProfileXY'
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
void makeSLDProfileXY(const emlrtStack *sp, real_T nbair, real_T nbsub, real_T
                      ssub, const emxArray_real_T *layers, real_T numberOfLayers,
                      real_T nrepeats, emxArray_real_T *out);

/* End of code generation (makeSLDProfileXY.h) */
