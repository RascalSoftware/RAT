/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * oneCellTest_initialize.c
 *
 * Code generation for function 'oneCellTest_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "oneCellTest.h"
#include "oneCellTest_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */
void oneCellTest_initialize(void)
{
  rt_InitInfAndNaN(8U);
  c_eml_rand_mt19937ar_stateful_i();
}

/* End of code generation (oneCellTest_initialize.c) */
