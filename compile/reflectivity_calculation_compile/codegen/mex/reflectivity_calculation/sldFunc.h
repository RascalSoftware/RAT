/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sldFunc.h
 *
 * Code generation for function 'sldFunc'
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
void sldFunc(const emlrtStack *sp, real_T x, const emxArray_real_T *SLD,
             emxArray_real_T *sldVal);

/* End of code generation (sldFunc.h) */
