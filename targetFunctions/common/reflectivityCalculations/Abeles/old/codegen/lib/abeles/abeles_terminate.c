/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles_terminate.c
 *
 * Code generation for function 'abeles_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "abeles.h"
#include "abeles_terminate.h"
#include "abeles_data.h"

/* Function Definitions */
void abeles_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/* End of code generation (abeles_terminate.c) */
