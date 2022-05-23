/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * resampleLayers.h
 *
 * Code generation for function 'resampleLayers'
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
void b_resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                      const real_T resamPars[2], emxArray_real_T *newSLD);

void resampleLayers(const emlrtStack *sp, const emxArray_real_T *sldProfile,
                    const real_T resamPars[2], emxArray_real_T *newSLD);

/* End of code generation (resampleLayers.h) */
