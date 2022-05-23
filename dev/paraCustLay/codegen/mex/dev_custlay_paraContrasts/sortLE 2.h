/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * sortLE.h
 *
 * Code generation for function 'sortLE'
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
boolean_T sortLE(const emxArray_real_T *v, const int32_T dir_data[],
                 int32_T idx1, int32_T idx2);

/* End of code generation (sortLE.h) */
