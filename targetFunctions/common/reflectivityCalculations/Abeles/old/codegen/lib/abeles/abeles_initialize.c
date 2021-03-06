/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles_initialize.c
 *
 * Code generation for function 'abeles_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "abeles.h"
#include "abeles_initialize.h"
#include "abeles_data.h"

/* Function Definitions */
void abeles_initialize(void)
{
  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
}

/* End of code generation (abeles_initialize.c) */
