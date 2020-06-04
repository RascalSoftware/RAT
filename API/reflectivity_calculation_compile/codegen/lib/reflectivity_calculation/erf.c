/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * erf.c
 *
 * Code generation for function 'erf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "reflectivity_calculation.h"
#include "erf.h"
#include "applyScalarFunction.h"
#include <string.h>

/* Function Definitions */
void b_erf(const emxArray_real_T *x, emxArray_real_T *y)
{
  applyScalarFunction(x, y);
}

/* End of code generation (erf.c) */
