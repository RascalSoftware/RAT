/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * linear_DE_new_test.h
 *
 * Code generation for function 'linear_DE_new_test'
 *
 */

#ifndef LINEAR_DE_NEW_TEST_H
#define LINEAR_DE_NEW_TEST_H

/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "linear_DE_new_test_types.h"

/* Function Declarations */
extern void intrafun(const double p_data[], const double problem_data[15],
                     double *S_MSE_I_nc, double *S_MSE_FVr_ca, double
                     *S_MSE_I_no, double *S_MSE_FVr_oa);
extern void linear_DE_new_test(const struct0_T *problem);

#endif

/* End of code generation (linear_DE_new_test.h) */
