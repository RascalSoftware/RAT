/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * asymconvstep.h
 *
 * Code generation for function 'asymconvstep'
 *
 */

#ifndef ASYMCONVSTEP_H
#define ASYMCONVSTEP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "reflectivity_calculation_types.h"

/* Function Declarations */
extern void asymconvstep(const emxArray_real_T *x, double xw, double xcen,
  double s1, double s2, double h, emxArray_real_T *f);

#endif

/* End of code generation (asymconvstep.h) */
