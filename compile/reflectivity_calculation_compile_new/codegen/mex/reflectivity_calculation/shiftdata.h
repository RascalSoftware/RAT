/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * shiftdata.h
 *
 * Code generation for function 'shiftdata'
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
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift,
               real_T dataPresent, emxArray_real_T *data,
               const real_T dataLimits[2], const real_T simLimits_data[],
               const int32_T simLimits_size[2], emxArray_real_T *shifted_data);

/* End of code generation (shiftdata.h) */
