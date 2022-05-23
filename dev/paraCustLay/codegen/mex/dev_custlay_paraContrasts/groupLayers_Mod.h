/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * groupLayers_Mod.h
 *
 * Code generation for function 'groupLayers_Mod'
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
void groupLayers_Mod(const emlrtStack *sp, const emxArray_real_T *allLayers,
                     real_T allRoughs, const emxArray_char_T *geometry,
                     real_T nbair, real_T nbsubs, emxArray_real_T *outLayers,
                     real_T *outSsubs);

/* End of code generation (groupLayers_Mod.h) */
