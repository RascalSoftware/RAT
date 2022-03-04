/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * call_customLayers.h
 *
 * Code generation for function 'call_customLayers'
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
void b_call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
                         real_T contrast, const cell_wrap_6 thisCustomFile[3],
                         const emxArray_real_T *bulkIn, real_T bulkOut,
                         real_T nContrasts, emxArray_real_T *output,
                         real_T *sRough);

void call_customLayers(const emlrtStack *sp, const emxArray_real_T *params,
                       real_T contrast, const cell_wrap_6 thisCustomFile[3],
                       real_T bulkIn, real_T bulkOut, real_T nContrasts,
                       emxArray_real_T *output, real_T *sRough);

/* End of code generation (call_customLayers.h) */
