/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * makeSLDProfileXY.h
 *
 * Code generation for function 'makeSLDProfileXY'
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
void binary_expand_op(const emlrtStack *sp, emxArray_real_T *SLD,
                      const emxArray_real_T *airBox,
                      const real_T subBox_data[]);

/* End of code generation (makeSLDProfileXY.h) */
