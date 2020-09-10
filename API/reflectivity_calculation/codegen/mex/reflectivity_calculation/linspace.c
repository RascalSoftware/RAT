/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * linspace.c
 *
 * Code generation for function 'linspace'
 *
 */

/* Include files */
#include "linspace.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void linspace(real_T d1, real_T d2, real_T y[50])
{
  int32_T k;
  real_T delta1;
  real_T delta2;
  y[49] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    for (k = 0; k < 48; k++) {
      y[k + 1] = d2 * ((2.0 * ((real_T)k + 2.0) - 51.0) / 49.0);
    }
  } else if (((d1 < 0.0) != (d2 < 0.0)) && ((muDoubleScalarAbs(d1) >
               8.9884656743115785E+307) || (muDoubleScalarAbs(d2) >
               8.9884656743115785E+307))) {
    delta1 = d1 / 49.0;
    delta2 = d2 / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = (d1 + delta2 * ((real_T)k + 1.0)) - delta1 * ((real_T)k + 1.0);
    }
  } else {
    delta1 = (d2 - d1) / 49.0;
    for (k = 0; k < 48; k++) {
      y[k + 1] = d1 + ((real_T)k + 1.0) * delta1;
    }
  }
}

/* End of code generation (linspace.c) */
