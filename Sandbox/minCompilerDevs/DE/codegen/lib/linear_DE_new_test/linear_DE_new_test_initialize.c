/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * linear_DE_new_test_initialize.c
 *
 * Code generation for function 'linear_DE_new_test_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "linear_DE_new_test.h"
#include "linear_DE_new_test_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand.h"

/* Function Definitions */
void linear_DE_new_test_initialize(void)
{
  rt_InitInfAndNaN(8U);
  method_not_empty_init();
  c_eml_rand_mt19937ar_stateful_i();
}

/* End of code generation (linear_DE_new_test_initialize.c) */
