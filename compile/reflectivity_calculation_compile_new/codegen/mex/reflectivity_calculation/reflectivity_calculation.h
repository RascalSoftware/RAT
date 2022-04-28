/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * reflectivity_calculation.h
 *
 * Code generation for function 'reflectivity_calculation'
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
emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void reflectivity_calculation(const emlrtStack *sp, const struct0_T *problemDef,
                              const cell_8 *problemDef_cells,
                              const struct1_T *problemDef_limits,
                              const struct2_T *controls, struct4_T *problem,
                              cell_11 *result);

/* End of code generation (reflectivity_calculation.h) */
