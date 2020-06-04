/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * chiSquared.h
 *
 * Code generation for function 'chiSquared'
 *
 */

#ifndef CHISQUARED_H
#define CHISQUARED_H

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_custlay_single_types.h"

/* Function Declarations */
extern double chiSquared(const double thisData_data[], const int thisData_size[2],
  const double thisFit_data[], const int thisFit_size[2], double P);

#endif

/* End of code generation (chiSquared.h) */
