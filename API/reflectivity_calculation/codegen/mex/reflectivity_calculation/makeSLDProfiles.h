/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * makeSLDProfiles.h
 *
 * Code generation for function 'makeSLDProfiles'
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
void makeSLDProfiles(const emlrtStack *sp, real_T nbair, real_T nbsub, const
                     emxArray_real_T *sld, real_T ssub, const real_T repeats[2],
                     emxArray_real_T *sldProfile);

/* End of code generation (makeSLDProfiles.h) */
