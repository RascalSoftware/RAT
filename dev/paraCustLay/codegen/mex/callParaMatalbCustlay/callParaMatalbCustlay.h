/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * callParaMatalbCustlay.h
 *
 * Code generation for function 'callParaMatalbCustlay'
 *
 */

#pragma once

/* Include files */
#include "callParaMatalbCustlay_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void callParaMatalbCustlay(const emlrtStack *sp, const struct0_T *problemDef,
                           const cell_8 *problemDef_cells,
                           const struct1_T *problemDef_limits,
                           const struct2_T *controls, const mxArray **outLayers,
                           const mxArray **allRoughs);

/* End of code generation (callParaMatalbCustlay.h) */
