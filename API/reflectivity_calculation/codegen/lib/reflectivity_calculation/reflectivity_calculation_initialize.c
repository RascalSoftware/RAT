/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * reflectivity_calculation_initialize.c
 *
 * Code generation for function 'reflectivity_calculation_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_initialize.h"
#include "reflectivity_calculation_data.h"

/* Function Definitions */
void reflectivity_calculation_initialize(void)
{
  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
}

/* End of code generation (reflectivity_calculation_initialize.c) */
