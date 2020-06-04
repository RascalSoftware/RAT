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
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "standardTF_stanlay_single_types.h"

/* Function Declarations */
extern void asymconvstep(const emxArray_real_T *x, double xw, double xcen,
  double s1, double s2, double h, emxArray_real_T *f);
extern void b_asymconvstep(const double x_data[], double xw, double xcen, double
  s1, double s2, double h, double f_data[], int f_size[2]);

#endif

/* End of code generation (asymconvstep.h) */
