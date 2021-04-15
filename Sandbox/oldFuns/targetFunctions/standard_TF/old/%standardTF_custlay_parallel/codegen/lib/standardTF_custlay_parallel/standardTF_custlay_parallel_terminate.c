/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * standardTF_custlay_parallel_terminate.c
 *
 * Code generation for function 'standardTF_custlay_parallel_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "standardTF_custlay_parallel.h"
#include "standardTF_custlay_parallel_terminate.h"
#include "standardTF_custlay_parallel_data.h"

/* Function Definitions */
void standardTF_custlay_parallel_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/* End of code generation (standardTF_custlay_parallel_terminate.c) */
