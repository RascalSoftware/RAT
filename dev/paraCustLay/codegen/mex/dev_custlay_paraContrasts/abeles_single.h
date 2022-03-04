/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles_single.h
 *
 * Code generation for function 'abeles_single'
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
void abeles_single(const emlrtStack *sp, const emxArray_real_T *x,
                   const emxArray_real_T *sld, real_T nbair, real_T nbsub,
                   real_T nrepeats, real_T rsub, real_T layers, real_T points,
                   emxArray_real_T *out);

/* End of code generation (abeles_single.h) */
